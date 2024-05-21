#include "scene.h"

#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <iostream>


ge::Scene::Scene()
        : current_frame_(nullptr) {
}

ge::Scene::Scene(const std::shared_ptr<Frame> &frame, std::string current_chapter_name,
                 int current_frame_number)
        : new_frame_(frame), current_chapter_name_(std::move(current_chapter_name)),
          current_frame_number_(current_frame_number) {
}

ge::Scene::Scene(const Scene &scene)
        : is_rendered_(scene.is_rendered_), new_frame_is_processed_(scene.new_frame_is_processed_),
          is_waiting_next_frame_(scene.is_waiting_next_frame_),
          current_frame_(scene.current_frame_), new_frame_(scene.new_frame_),
          current_chapter_name_(scene.current_chapter_name_),
          current_frame_number_(scene.current_frame_number_), sfml_basis_(scene.sfml_basis_),
          selected_row_button_(scene.selected_row_button_),
          selected_column_button_(scene.selected_column_button_) {
}

ge::Scene::Scene(Scene &scene)
        : is_rendered_(scene.is_rendered_), new_frame_is_processed_(scene.new_frame_is_processed_),
          is_waiting_next_frame_(scene.is_waiting_next_frame_),
          current_frame_(scene.current_frame_), new_frame_(scene.new_frame_),
          current_chapter_name_(scene.current_chapter_name_),
          current_frame_number_(scene.current_frame_number_), sfml_basis_(scene.sfml_basis_),
          selected_row_button_(scene.selected_row_button_),
          selected_column_button_(scene.selected_column_button_) {
}

ge::Scene::Scene(Scene &&scene) noexcept
        : is_rendered_(scene.is_rendered_), new_frame_is_processed_(scene.new_frame_is_processed_),
          is_waiting_next_frame_(scene.is_waiting_next_frame_),
          current_frame_(std::move(scene.current_frame_)), new_frame_(std::move(scene.new_frame_)),
          current_chapter_name_(std::move(scene.current_chapter_name_)),
          current_frame_number_(scene.current_frame_number_), sfml_basis_(std::move(scene.sfml_basis_)),
          selected_row_button_(scene.selected_row_button_),
          selected_column_button_(scene.selected_column_button_) {
}

ge::Scene &ge::Scene::operator=(const Scene &scene) {
    is_rendered_ = scene.is_rendered_;
    new_frame_is_processed_ = scene.new_frame_is_processed_;
    is_waiting_next_frame_ = scene.is_waiting_next_frame_;
    current_frame_ = scene.current_frame_;
    new_frame_ = scene.new_frame_;
    current_chapter_name_ = scene.current_chapter_name_;
    current_frame_number_ = scene.current_frame_number_;
    sfml_basis_ = scene.sfml_basis_;
    selected_row_button_ = scene.selected_row_button_;
    selected_column_button_ = scene.selected_column_button_;
    return *this;
}

ge::Scene &ge::Scene::operator=(Scene &&scene) noexcept {
    is_rendered_ = scene.is_rendered_;
    new_frame_is_processed_ = scene.new_frame_is_processed_;
    is_waiting_next_frame_ = scene.is_waiting_next_frame_;
    current_frame_ = std::move(scene.current_frame_);
    new_frame_ = std::move(scene.new_frame_);
    current_chapter_name_ = std::move(scene.current_chapter_name_);
    current_frame_number_ = scene.current_frame_number_;
    sfml_basis_ = std::move(scene.sfml_basis_);
    selected_row_button_ = scene.selected_row_button_;
    selected_column_button_ = scene.selected_column_button_;
    return *this;
}

void ge::Scene::setNewFrame(const std::shared_ptr<Frame> &frame) {
    is_waiting_next_frame_ = false;
    new_frame_ = frame;
    new_frame_is_processed_ = false;
}

void ge::Scene::setSlotSpriteParameters(const sf::Vector2u &window_size) {
    if (sfml_basis_->slots_sprites.size() != sfml_basis_->slots_textures.size()) {
        return;
    }
    size_t slots_quantity = sfml_basis_->slots_sprites.size();
    if (slots_quantity > 0) {
        float distance_between_slots =
                static_cast<float>(window_size.x) / (static_cast<float>(slots_quantity + 1) * 1.3f);
        float slot_scale = 0.8f * static_cast<float>(window_size.y) / 3270.0f;
        float left_slot_offset =
                (static_cast<float>(window_size.x) - distance_between_slots * static_cast<float>(slots_quantity - 1)) /
                2.0f;

        for (size_t i = 0; i < slots_quantity; ++i) {
            sfml_basis_->slots_sprites[i].setScale(slot_scale, slot_scale);

            sf::Vector2f slot_picture_size = {sfml_basis_->slots_sprites[i].getLocalBounds().width,
                                              sfml_basis_->slots_sprites[i].getLocalBounds().height};
            sfml_basis_->slots_sprites[i].setOrigin(slot_picture_size.x / 2, slot_picture_size.y);
            sf::Vector2f slot_coords = {left_slot_offset + distance_between_slots * static_cast<float>(i),
                                        static_cast<float>(window_size.y) * 1.2f};
            sfml_basis_->slots_sprites[i].setPosition(slot_coords);
        }
    }
}

unsigned int ge::Scene::getSelectedRow() const {
    return selected_row_button_;
}

unsigned int ge::Scene::getSelectedColumn() const {
    return selected_column_button_;
}

bool ge::Scene::getChoiceOfActions() const {
    return current_frame_->getChoiceOfAction();
}

void ge::Scene::moveUp() {
    if (selected_row_button_ == ROW_ACTION_OR_DIALOGUE) {
        return;
    }

    if (!is_rendered_) {
        --selected_row_button_;
        return;
    }

    sfml_basis_->button_backgrounds[selected_column_button_].setOutlineColor(sf::Color::Black);

    if (current_frame_->getChoiceOfAction()) {
        if (!current_frame_->getActions().empty()) {
            selected_column_button_ = std::min(static_cast<size_t>(selected_column_button_),
                                               sfml_basis_->action_buttons.size() - 1);
            sfml_basis_->action_buttons[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);
        }
    } else {
        sfml_basis_->next_background.setOutlineColor(HIGHLIGHT_COLOR);
    }

    --selected_row_button_;
}

void ge::Scene::moveDown() {
    if (selected_row_button_ == ROW_BUTTONS) {
        return;
    }
    if (!is_rendered_) {
        ++selected_row_button_;
        selected_column_button_ = std::min(selected_column_button_, BUTTONS_QUANTITY - 1);
        return;
    }

    if (current_frame_->getChoiceOfAction()) {
        if (!current_frame_->getActions().empty()) {
            sfml_basis_->action_buttons[selected_column_button_].setOutlineColor(sf::Color::Black);
        }
    } else {
        sfml_basis_->next_background.setOutlineColor(sf::Color::Black);
    }
    selected_column_button_ = std::min(selected_column_button_, BUTTONS_QUANTITY - 1);
    sfml_basis_->button_backgrounds[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);

    ++selected_row_button_;
}

void ge::Scene::moveLeft() {
    if ((selected_row_button_ == ROW_ACTION_OR_DIALOGUE &&
         (!current_frame_->getChoiceOfAction() || current_frame_->getActions().size() <= 1)) ||
        selected_column_button_ == 0) {
        return;
    }
    --selected_column_button_;
    if (!is_rendered_) {
        return;
    }
    if (selected_row_button_ == ROW_ACTION_OR_DIALOGUE) {
        sfml_basis_->action_buttons[selected_column_button_ + 1].setOutlineColor(sf::Color::Black);
        sfml_basis_->action_buttons[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);
    } else {
        sfml_basis_->button_backgrounds[selected_column_button_ + 1].setOutlineColor(sf::Color::Black);
        sfml_basis_->button_backgrounds[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);
    }
}

void ge::Scene::moveRight() {
    if (selected_row_button_ == ROW_ACTION_OR_DIALOGUE &&
        (!current_frame_->getChoiceOfAction() || current_frame_->getActions().size() <= 1)) {
        return;
    }
    if (selected_row_button_ == ROW_ACTION_OR_DIALOGUE) {
        if (selected_column_button_ == sfml_basis_->action_buttons.size() - 1) {
            return;
        }
        ++selected_column_button_;
        if (is_rendered_) {
            sfml_basis_->action_buttons[selected_column_button_ - 1].setOutlineColor(sf::Color::Black);
            sfml_basis_->action_buttons[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);
        }
        return;
    }
    if (selected_column_button_ == BUTTONS_QUANTITY - 1) {
        return;
    }
    ++selected_column_button_;
    if (is_rendered_) {
        sfml_basis_->button_backgrounds[selected_column_button_ - 1].setOutlineColor(sf::Color::Black);
        sfml_basis_->button_backgrounds[selected_column_button_].setOutlineColor(HIGHLIGHT_COLOR);
    }
}

void ge::Scene::waitNextFrame() {
    selected_row_button_ = 0;
    selected_column_button_ = 0;
    ++current_frame_number_;
    is_waiting_next_frame_ = true;
}

void ge::Scene::waitNextChapter() {
    selected_row_button_ = 0;
    selected_column_button_ = 0;
    if (!current_frame_->getChoiceOfAction()) {
        throw std::runtime_error("can't wait next chapter until current frame is choice of action");
    }
    size_t quantity_of_actions = current_frame_->getActions().size();
    if (quantity_of_actions == 0) {
        return;
    }
    if (selected_column_button_ >= current_frame_->getActions().size()) {
        throw std::runtime_error("number of selected action is outside of the boundaries of the vector of actions");
    }
    current_frame_number_ = 0;
    current_chapter_name_ = current_frame_->getActions()[selected_column_button_].getChapterNameToGo();
    is_waiting_next_frame_ = true;
}

std::string ge::Scene::getBackground() const {
    return current_frame_->getBackgroundFile();
}

const std::vector<ge::Action> &ge::Scene::getActions() const {
    if (!current_frame_ || !current_frame_->getChoiceOfAction()) {
        throw std::runtime_error("current frame not exists\n");
    }
    return current_frame_->getActions();
}

const ge::DialogueBox &ge::Scene::getDialogueBox() const {
    if (!current_frame_ || current_frame_->getChoiceOfAction()) {
        throw std::runtime_error("current frame not exists\n");
    }
    return current_frame_->getDialogueBox();
}

void ge::Scene::processNewFrame() {
    if (!is_rendered_) {
        throw std::runtime_error("sfml_basis_ was not rendered to render new frame\n");
    }
    if (new_frame_ == nullptr) {
        throw std::runtime_error("new_frame_ was not set to process new frame\n");
    }

    // Updating background
    if (new_frame_->getBackgroundFile() != current_frame_->getBackgroundFile()) {
        if (!sfml_basis_->background_texture.loadFromFile(new_frame_->getBackgroundFile())) {
            throw std::runtime_error("can't load background file\n");
        }
        sfml_basis_->background_sprite.setTexture(sfml_basis_->background_texture);
    }

    // Updating frame slots (optimized)
    std::vector<std::string> new_paths = new_frame_->getSlots().getPicturesInSlots();
    std::vector<std::string> current_paths = current_frame_->getSlots().getPicturesInSlots();
    if (current_paths.size() < new_paths.size()) {
        current_paths.resize(new_paths.size());
        sfml_basis_->slots_sprites.resize(new_paths.size());
        sfml_basis_->slots_textures.resize(new_paths.size());
    }
    std::unordered_set<size_t> fined;
    for (size_t i = 0; i < std::min(new_paths.size(), current_paths.size()); ++i) {
        for (size_t j = 0; j < current_paths.size(); ++j) {
            if (fined.find(j) != fined.end() || current_paths[j] != new_paths[i]) {
                continue;
            }
            std::swap(current_paths[i], current_paths[j]);
            std::swap(sfml_basis_->slots_sprites[i], sfml_basis_->slots_sprites[j]);
            std::swap(sfml_basis_->slots_textures[i], sfml_basis_->slots_textures[j]);
            fined.insert(i);
            break;
        }
    }
    current_paths.resize(new_paths.size());
    for (size_t i = 0; i < current_paths.size(); ++i) {
        if (fined.find(i) != fined.end() || new_paths[i].empty()) {
            continue;
        }
        if (!sfml_basis_->slots_textures[i].loadFromFile(new_paths[i])) {
            throw std::runtime_error("can't load sprite file\n");
        }
        sfml_basis_->slots_sprites[i].setTexture(sfml_basis_->slots_textures[i]);
    }
    sfml_basis_->slots_sprites.resize(new_paths.size());
    sfml_basis_->slots_textures.resize(new_paths.size());

    setSlotSpriteParameters(sfml_basis_->window_size);

    // Updating dialogue box
    sfml_basis_->replica.setString(new_frame_->getDialogueBox().getReplica());
    sfml_basis_->speaker.setString(new_frame_->getDialogueBox().getSpeaker());

    // Updating actions
    if (new_frame_->getActions() != current_frame_->getActions()) {
        const std::vector<Action> &new_actions = new_frame_->getActions();
        sfml_basis_->action_buttons.clear();
        sfml_basis_->action_buttons.resize(new_actions.size());
        for (size_t i = 0; i < new_actions.size(); ++i) {
            sf::Text &action_button_i = sfml_basis_->action_buttons[i];
            auto action_button_size = static_cast<unsigned int>(sfml_basis_->window_size.y * 0.035);
            sf::Vector2f action_relative_coords = new_actions[i].getCoords();
            sf::Vector2f action_button_coords = {action_relative_coords.x *
                                                 static_cast<float>(sfml_basis_->window_size.x),
                                                 action_relative_coords.y *
                                                 static_cast<float>(sfml_basis_->window_size.y)};
            action_button_i.setFont(sfml_basis_->font);
            action_button_i.setCharacterSize(action_button_size);
            action_button_i.setString(new_actions[i].getText());
            action_button_i.setOutlineThickness(3);
            action_button_i.setOrigin(action_button_i.getGlobalBounds().getSize() / 2.0f +
                                      action_button_i.getLocalBounds().getPosition());
            action_button_i.setPosition(action_button_coords);
            action_button_i.setFillColor(sf::Color::White);
            action_button_i.setOutlineColor(sf::Color::Black);
        }
    }

    // Setting colors
    if (new_frame_->getChoiceOfAction()) {
        sfml_basis_->replica.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->next.setFillColor(sf::Color::Transparent);
        sfml_basis_->next.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->replica_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica_background.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker_background.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->next_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->next_background.setOutlineColor(sf::Color::Transparent);
        for (size_t i = 0; i < sfml_basis_->action_buttons.size(); ++i) {
            sfml_basis_->action_buttons[i].setFillColor(sf::Color::White);
            if (i == selected_column_button_) {
                sfml_basis_->action_buttons[i].setOutlineColor(HIGHLIGHT_COLOR);
            } else {
                sfml_basis_->action_buttons[i].setOutlineColor(sf::Color::Black);
            }
        }
    } else {
        if (new_frame_->getDialogueBox().getSpeaker().empty() || new_frame_->getDialogueBox().getReplica().empty()) {
            sfml_basis_->speaker.setFillColor(sf::Color::Transparent);
            sfml_basis_->speaker.setOutlineColor(sf::Color::Transparent);
            sfml_basis_->speaker_background.setFillColor(sf::Color::Transparent);
            sfml_basis_->speaker_background.setOutlineColor(sf::Color::Transparent);
        } else {
            sfml_basis_->speaker.setFillColor(sf::Color::White);
            sfml_basis_->speaker.setOutlineColor(sf::Color::Black);
            sfml_basis_->speaker_background.setFillColor(BACKGROUNDS_FILL_COLOR);
            sfml_basis_->speaker_background.setOutlineColor(sf::Color::Black);
        }
        if (new_frame_->getDialogueBox().getReplica().empty()) {
            sfml_basis_->replica.setFillColor(sf::Color::Transparent);
            sfml_basis_->replica.setOutlineColor(sf::Color::Transparent);
            sfml_basis_->replica_background.setFillColor(sf::Color::Transparent);
            sfml_basis_->replica_background.setOutlineColor(sf::Color::Transparent);
        } else {
            sfml_basis_->replica.setFillColor(sf::Color::White);
            sfml_basis_->replica.setOutlineColor(sf::Color::Black);
            sfml_basis_->replica_background.setFillColor(BACKGROUNDS_FILL_COLOR);
            sfml_basis_->replica_background.setOutlineColor(sf::Color::Black);
        }

        if (current_frame_->getChoiceOfAction()) {
            sfml_basis_->next.setFillColor(sf::Color::White);
            sfml_basis_->next.setOutlineColor(sf::Color::Black);
            sfml_basis_->next_background.setFillColor(BACKGROUNDS_FILL_COLOR);
            sfml_basis_->next_background.setOutlineColor(sf::Color::White);
            for (sf::Text &action_button: sfml_basis_->action_buttons) {
                action_button.setFillColor(sf::Color::Transparent);
                action_button.setOutlineColor(sf::Color::Transparent);
            }
        }
    }
    current_frame_ = new_frame_;
    new_frame_ = nullptr;
    new_frame_is_processed_ = true;
    is_waiting_next_frame_ = false;
}

bool ge::Scene::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_ && new_frame_is_processed_) {
        return true;
    }
    if (is_rendered_ && !new_frame_is_processed_) {
        processNewFrame();
        return true;
    }

    sfml_basis_ = std::make_shared<SceneSfmlBasis>();

    sfml_basis_->window_size = window_size;

    // setting background
    if (!sfml_basis_->background_texture.loadFromFile(new_frame_->getBackgroundFile())) {
        return false;
    }
    sfml_basis_->background_sprite.setTexture(sfml_basis_->background_texture);
    sfml_basis_->background_sprite.scale({
                                                 static_cast<float>(window_size.x) / 3840.0f,
                                                 static_cast<float>(window_size.y) / 2160.0f
                                         });

    // setting slot pictures
    size_t slots_quantity = new_frame_->getSlots().getQuantityOfSlots();
    sfml_basis_->slots_textures.resize(slots_quantity);
    sfml_basis_->slots_sprites.resize(slots_quantity);
    if (slots_quantity > 0) {
        const std::vector<std::string> &pictures_in_slots = new_frame_->getSlots().getPicturesInSlots();
        for (size_t i = 0; i < slots_quantity; ++i) {
            sfml_basis_->slots_textures[i].loadFromFile(pictures_in_slots[i]);
            sfml_basis_->slots_sprites[i].setTexture(sfml_basis_->slots_textures[i]);
        }
        setSlotSpriteParameters(window_size);
    }

    // setting font
    if (!sfml_basis_->font.loadFromFile(FONT_NAME)) {
        return false;
    }

    // setting actions
    const std::vector<Action> &actions = new_frame_->getActions();
    sfml_basis_->action_buttons.resize(actions.size());
    for (size_t i = 0; i < actions.size(); ++i) {
        sf::Text &action_buttons_i = sfml_basis_->action_buttons[i];
        action_buttons_i.setFont(sfml_basis_->font);
        action_buttons_i.setString(actions[i].getText());
        action_buttons_i.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.035));
        action_buttons_i.setOutlineThickness(2);
        action_buttons_i.setOrigin(action_buttons_i.getGlobalBounds().width / 2,
                                   action_buttons_i.getGlobalBounds().height / 2);
        action_buttons_i.setPosition(static_cast<float>(window_size.x) * actions[i].getCoords().x,
                                     static_cast<float>(window_size.y) * actions[i].getCoords().y);
    }

    // setting speaker background
    sf::Vector2f speaker_background_size = {static_cast<float>(window_size.x) * 0.21f,

                                            static_cast<float>(window_size.y) * 0.04f};
    sf::Vector2f speaker_background_position = {static_cast<float>(window_size.x) * 0.14f,
                                                static_cast<float>(window_size.y) * 0.752f};
    sfml_basis_->speaker_background.setOutlineThickness(3);
    sfml_basis_->speaker_background.setSize(
            speaker_background_size);
    sfml_basis_->speaker_background.setPosition(speaker_background_position);

    // setting speaker
    sfml_basis_->speaker.setFont(sfml_basis_->font);
    sfml_basis_->speaker.setString(new_frame_->getDialogueBox().getSpeaker());
    sfml_basis_->speaker.setOutlineThickness(2);
    sfml_basis_->speaker.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sf::Vector2f speaker_size = {sfml_basis_->speaker.getLocalBounds().width,
                                 sfml_basis_->speaker.getLocalBounds().height};
    sfml_basis_->speaker.setOrigin(0, sfml_basis_->speaker.getGlobalBounds().getSize().y / 2.f +
                                      sfml_basis_->speaker.getLocalBounds().getPosition().y);
    sfml_basis_->speaker.setPosition(speaker_background_position.x + speaker_background_size.x * 0.02f,
                                     speaker_background_position.y + (speaker_background_size.y / 2.f));


    // setting replica box
    sf::Vector2f replica_background_size = {static_cast<float>(window_size.x) - 2.0f * speaker_background_position.x,
                                            static_cast<float>(window_size.y) * 0.14f};
    sf::Vector2f replica_background_position = {speaker_background_position.x,
                                                speaker_background_position.y + speaker_background_size.y * 1.3f};
    sfml_basis_->replica_background.setSize(
            replica_background_size);
    sfml_basis_->replica_background.setPosition(replica_background_position);
    sfml_basis_->replica_background.setOutlineThickness(3);

    sfml_basis_->replica.setFont(sfml_basis_->font);
    sfml_basis_->replica.setString(new_frame_->getDialogueBox().getReplica());
    sfml_basis_->replica.setOutlineThickness(2);
    sfml_basis_->replica.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sfml_basis_->replica.setPosition(replica_background_position.x + speaker_background_size.x * 0.02f,
                                     replica_background_position.y);

    // setting next_button
    sfml_basis_->next.setFont(sfml_basis_->font);
    sfml_basis_->next.setString(NEXT_BUTTON_TEXT);
    sfml_basis_->next.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sfml_basis_->next.setOutlineThickness(2);

    sf::Vector2f next_background_size = {sfml_basis_->next.getGlobalBounds().getSize().x * 1.3f,
                                         speaker_background_size.y};
    sfml_basis_->next_background.setSize(next_background_size);
    sfml_basis_->next_background.setOutlineThickness(3);

    sf::Vector2f next_background_position = {
            replica_background_size.x + replica_background_position.x - next_background_size.x,
            speaker_background_position.y};
    sfml_basis_->next_background.setPosition(next_background_position);

    sfml_basis_->next.setOrigin(
            sfml_basis_->next.getGlobalBounds().getSize() / 2.f + sfml_basis_->next.getLocalBounds().getPosition());
    sfml_basis_->next.setPosition(
            sfml_basis_->next_background.getPosition() + (sfml_basis_->next_background.getSize() / 2.f));

    // setting replica, next and speaker colors
    if (new_frame_->getChoiceOfAction()) {
        sfml_basis_->replica.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->replica_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica_background.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker_background.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->next_background.setFillColor(sf::Color::Transparent);
        sfml_basis_->next_background.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->next.setFillColor(sf::Color::Transparent);
        sfml_basis_->next.setOutlineColor(sf::Color::Transparent);
        for (size_t i = 0; i < sfml_basis_->action_buttons.size(); ++i) {
            sfml_basis_->action_buttons[i].setFillColor(sf::Color::White);
            if (i == selected_column_button_) {
                sfml_basis_->action_buttons[i].setOutlineColor(HIGHLIGHT_COLOR);
            } else {
                sfml_basis_->action_buttons[i].setOutlineColor(sf::Color::Black);
            }
        }
    } else {
        sfml_basis_->next_background.setFillColor(BACKGROUNDS_FILL_COLOR);
        sfml_basis_->next_background.setOutlineColor(HIGHLIGHT_COLOR);
        sfml_basis_->next.setFillColor(sf::Color::White);
        sfml_basis_->next.setOutlineColor(sf::Color::Black);

        if (new_frame_->getDialogueBox().getSpeaker().empty() || new_frame_->getDialogueBox().getReplica().empty()) {
            sfml_basis_->speaker.setFillColor(sf::Color::Transparent);
            sfml_basis_->speaker.setOutlineColor(sf::Color::Transparent);
            sfml_basis_->speaker_background.setFillColor(sf::Color::Transparent);
            sfml_basis_->speaker_background.setOutlineColor(sf::Color::Transparent);
        } else {
            sfml_basis_->speaker.setFillColor(sf::Color::White);
            sfml_basis_->speaker.setOutlineColor(sf::Color::Black);
            sfml_basis_->speaker_background.setFillColor(BACKGROUNDS_FILL_COLOR);
            sfml_basis_->speaker_background.setOutlineColor(sf::Color::Black);
        }
        if (new_frame_->getDialogueBox().getReplica().empty()) {
            sfml_basis_->replica.setFillColor(sf::Color::Transparent);
            sfml_basis_->replica.setOutlineColor(sf::Color::Transparent);
            sfml_basis_->replica_background.setFillColor(sf::Color::Transparent);
            sfml_basis_->replica_background.setOutlineColor(sf::Color::Transparent);
        } else {
            sfml_basis_->replica.setFillColor(sf::Color::White);
            sfml_basis_->replica.setOutlineColor(sf::Color::Black);
            sfml_basis_->replica_background.setFillColor(BACKGROUNDS_FILL_COLOR);
            sfml_basis_->replica_background.setOutlineColor(sf::Color::Black);
        }

        for (sf::Text &action_button: sfml_basis_->action_buttons) {
            action_button.setFillColor(sf::Color::Transparent);
            action_button.setOutlineColor(sf::Color::Transparent);
        }
    }

    // setting bottom buttons

    float circle_radius = static_cast<float>(window_size.y) * 0.02f;
    float distance_between_buttons = circle_radius * 3.0f;
    float buttons_left_offset =
            (static_cast<float>(window_size.x) - distance_between_buttons * static_cast<float>(BUTTONS_QUANTITY - 1)) /
            2.0f;
//    float buttons_up_offset = static_cast<float>(window_size.y) * 1.5f - (replica_background_position.y + replica_background_size.y) / 2.0f;

    float buttons_up_offset = static_cast<float>(window_size.y) * 0.973f;
    sfml_basis_->button_backgrounds.resize(BUTTONS_QUANTITY);
    sfml_basis_->button_symbols.resize(BUTTONS_QUANTITY);

    for (size_t i = 0; i < BUTTONS_QUANTITY; ++i) {
        sfml_basis_->button_backgrounds[i].setRadius(circle_radius);
        sfml_basis_->button_backgrounds[i].setOutlineThickness(3);
        sfml_basis_->button_backgrounds[i].setOrigin(
                sfml_basis_->button_backgrounds[i].getGlobalBounds().getSize() / 2.f +
                sfml_basis_->button_backgrounds[i].getLocalBounds().getPosition());
        sfml_basis_->button_backgrounds[i].setPosition(
                buttons_left_offset + distance_between_buttons * static_cast<float>(i), buttons_up_offset);
        sfml_basis_->button_backgrounds[i].setFillColor(BACKGROUNDS_FILL_COLOR);
        sfml_basis_->button_backgrounds[i].setOutlineColor(sf::Color::Black);

        sfml_basis_->button_symbols[i].setFont(sfml_basis_->font);
        sfml_basis_->button_symbols[i].setString(BUTTON_SYMBOLS[i]);
        sfml_basis_->button_symbols[i].setCharacterSize(static_cast<unsigned int>(circle_radius / 1.2f));
        sfml_basis_->button_symbols[i].setOutlineThickness(2);
        sfml_basis_->button_symbols[i].setOrigin(sfml_basis_->button_symbols[i].getGlobalBounds().getSize() / 2.f +
                                                 sfml_basis_->button_symbols[i].getLocalBounds().getPosition());
        sfml_basis_->button_symbols[i].setPosition(sfml_basis_->button_backgrounds[i].getPosition());
        sfml_basis_->button_symbols[i].setFillColor(sf::Color::White);
        sfml_basis_->button_symbols[i].setOutlineColor(sf::Color::Black);
    }
    current_frame_ = new_frame_;
    new_frame_.reset();
    is_rendered_ = true;
    new_frame_is_processed_ = true;
    return true;
}

void ge::Scene::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::Scene::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}