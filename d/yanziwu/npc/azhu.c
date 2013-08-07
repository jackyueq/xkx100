// azhu.c

inherit NPC;
inherit F_SKILL;
int inquiry_tanqin();

void create()
{
	set_name("°¢Öì", ({ "azhu", "zhu" }));
	set("long",
		"ÕâÊÇ¸öÉí´©ºìÒÂµÄÅ®ÀÉ£¬´óÔ¼Ê®Æß°ËËê£¬Ò»Á³¾«ÁéÍçÆ¤µÄÉñÆø¡£\n"
		"Ò»ÕÅ¶ìµ°Á³£¬ÑÛÖéÁé¶¯£¬±ğÓĞÒ»·¬¶¯ÈË·çÔÏ¡£\n");

	set("gender", "Å®ĞÔ");
	set("age", 17);
	set("per", 29);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);
	set_skill("strike", 40);
	set_skill("finger", 40);
	set_skill("murong-sword", 30);
	set_skill("murong-blade", 30);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 30);
	set_skill("yanling-shenfa", 30);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");

	set("combat_exp", 10000);
	set("inquiry",([
		"ÂüÍÓÉ½×¯" : "ÎÒ²Å²»¸ÒÈ¥ÂüÍÓÉ½×¯£¬Íõ·òÈËÌ«°ÔµÀÁË£¡\n",
		"ÍõÓïæÌ" : "°¥£¬Ö»ÓĞËı²ÅÅäµÃÉÏÎÒÃÇ¹«×Ó£¬Ò²²»ÖªËıÏÖÔÚÔõÑùÁË£¡\n",
		"°¢±Ì" : "ÄÇĞ¡Ñ¾Í·Ò²²»Ö»ÅÜÄÄ¶ùÈ¥ÁË¡£\n",
		"µ¯ÇÙ" : ( : inquiry_tanqin : ),
	]) );
	create_family("¹ÃËÕÄ½Èİ", 33, "µÜ×Ó");
	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object("clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/pink_cloth")->wear();
	carry_object(__DIR__"obj/flower_shoe")->wear();
	carry_object("clone/misc/mask");
}

int inquiry_tanqin()
{
	object me=this_player();
message_vision("°¢ÖìËµµÀ£ºÕâÎ»"+ RANK_D->query_respect(me)+"ÕâÃ´ÓĞÑÅĞË£¬ÄÇÎÒ¾ÍÎªÄãµ¯×àÒ»Çú£ \nÖ»ÌıÇÙÉù·±¸´ÇåÁÁ£¬Äã²»ÓÉµÄ³ÕÁË¡£\n", me );
//	Ï¸Ï¸Æ·À´£¬¾¹ÊÇÕÅĞÅÕÜµÄ<<°®Èç³±Ë®>>!!!\n 
	message_vision("°¢ÖìÒ»ÇúÖÕÁË£¬µÀ¸öÍò¸££¬ËµµÀ£ºÏÖ³óÁË¡£\n", me );
	return 1;
}
