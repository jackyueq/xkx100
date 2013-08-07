// azhu.c

inherit NPC;
inherit F_SKILL;
int inquiry_tanqin();

void create()
{
	set_name("╟╒жЛ", ({ "a zhu", "zhu" }));
	set("long",
		"уБйг╦ЖиМ╢╘╨Лрб╣де╝юиё╛╢Ст╪й╝фъ╟ккЙё╛р╩аЁ╬╚аИмГф╓╣диЯфЬ║ё\n"
		"р╩уе╤Л╣╟аЁё╛яшжИаИ╤╞ё╛╠Пспр╩╥╛╤╞хк╥Гто║ё\n");
	set("gender", "е╝пт");
	set("class", "scholar");
	set("age", 17);
	set("per", 29);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("blade", 50);
	set_skill("strike", 50);
	set_skill("finger", 50);
	set_skill("murong-sword", 50);
	set_skill("murong-blade", 50);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 50);
	set_skill("yanling-shenfa", 50);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("env/wimpy", 60);

	set("combat_exp", 10000);
	set("inquiry",([
		"бЭмси╫в╞" : "нр╡е╡╩╦рх╔бЭмси╫в╞ё╛мУ╥Рхкл╚╟т╣юакё║\n",
		"мУсОФл" : "╟╔ё╛ж╩спкЩ╡ееД╣ционрцг╧╚всё╛р╡╡╩ж╙кЩожтзтУяЫакё║\n",
		"╟╒╠л" : "дгп║я╬м╥р╡╡╩ж╩еэдд╤Ых╔ак║ё\n",
		"╣╞гы" : ( : inquiry_tanqin : ),
		"дод╫хщ" : "нр╪р╧╚вс╨мь╓╟Огг╟ОжВфКцШё╛╨оЁф║╟дод╫хщ╠╠гг╥Е║╠ё║\n",
		"д╫хщ╦╢"   : "╟╔ё╛уБдЦр╡╡╩╤╝ё╛кШ╬мйгнр╪р╧╚всё║\n",
		"мУ╥Рхк"   : "╬мйг╧╚вср╞╣д╬кбХё╛бЭмси╫в╞╣дв╞жВё║\n",
		"╣к╟ы╢╗"   : "дЦнй╣к╢С╦Г╟║ё©кШтзкШгЮ╥Гв╞иодь║ё\n",
		"╧╚р╠г╛"   : "╧╚р╠╤Ч╦Г╟япе╦К╢╚йИр╩╠ЮбКё╛╬мц╩╪╦╦Жхк╤а╣ц╤╝ак║ё\n",
		"╟Э╡╩м╛"   : "╟ЭхЩ╦ГвН╟╝л╖╦эакё╛дЦ╪ШаккШ╩╧йг╠увЛ╣д╨ц║ё\n",
		"╥Г╡╗╤Я"   : "╥Гкд╦ГвНйг╨юк╛акё╛кШ╢с╡╩сКхк╪ф╫ой╡ц╢║ё\n",
	]) );
	create_family("╧цкуд╫хщ", 33, "╣эвс");
	setup();
	carry_object("/d/yanziwu/npc/obj/goldring")->wear();
	carry_object("/d/yanziwu/npc/obj/necklace")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/yanziwu/npc/obj/pink_cloth")->wear();
	carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
	carry_object("/clone/misc/mask");
}

int inquiry_tanqin()
{
	object me=this_player();
message_vision("╟╒жЛк╣╣юё╨уБн╩"+ RANK_D->query_respect(me)+"уБц╢спяепкё╛дгнр╬мн╙дЦ╣╞вЮр╩гЗё \nж╩лЩгыиЫ╥╠╦╢гЕааё╛дЦ╡╩си╣дЁуак║ё\n", me );
//	о╦о╦ф╥ю╢ё╛╬╧йгуепеуэ╣д<<╟╝хГЁ╠к╝>>!!!\n 
	message_vision("╟╒жЛр╩гЗжуакё╛╣ю╦ЖмР╦ёё╛к╣╣юё╨ожЁСак║ё\n", me );
	return 1;
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say уБн╩" + RANK_D->query_respect(ob) +
			"ё╛нрд╫хщ╪р╦╢╧Здкжан╙р╙йбё╛дЦпдж╬╡╩╪Аё╛нчт╣нрце║ё");
		return;
	}
	command("say ╨ц╟инр╬мйудЦн╙м╫╟и║ё");
	command("recruit " + ob->query("id"));
}
