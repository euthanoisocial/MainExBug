#include "stdafx.h"
#include "EmojiSystem.h"
#include "Util.h"
#include "Protect.h"

CEmojis gEmojis;

CEmojis::CEmojis()
{

}

CEmojis::~CEmojis()
{

}


void CEmojis::LoadImages()
{
	//if (gProtect.m_MainInfo.gEmojis == 1)
	{
		pLoadImage("Custom\\Emojis\\emojis_f.tga", TEXTURE_EMOJI_LIST1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\emojis_f2.tga", TEXTURE_EMOJI_LIST2, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\emojis_f3.tga", TEXTURE_EMOJI_LIST3, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\emoji_list_btn.tga", TEXTURE_EMOJI_LIST_BTN, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\newui_chat_emoji_on.jpg", TEXTURE_EMOJI_LIST_ON, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\btn_arrow.tga", TEXTURE_EMOJI_LIST_ARROW, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Emojis\\newui_chat_back.jpg", 31279, GL_LINEAR, GL_CLAMP, 1, 0);
	}
}

void CEmojis::AddTextures()
{
	//if (gProtect.m_MainInfo.gEmojis == 1)
	{
		myheart::MUEmoji::Init(TEXTURE_EMOJI_LIST_ARROW, TEXTURE_EMOJI_LIST_ON, TEXTURE_EMOJI_LIST_BTN, 20, 14, 4, 0);

		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST1, 361);

		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST2, 309);

		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST3, 118);
	}
}