// Npc: /kungfu/class/nanshaolin/fangchen.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me(string name);

void create()
{
	set_name("����", ({ "fang chen", "fang", "chen"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "����ͷ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("whip", 50);
	set_skill("jiujie-whip", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("whip", "jiujie-whip");
	map_skill("parry", "jiujie-whip");
	prepare_skill("cuff", "luohan-cuff");
	prepare_skill("hand", "fengyun-hand");

	set("inquiry", ([
		"����" : (: ask_me, "changjian" :),
		"��"   : (: ask_me, "changjian" :),
		"�䵶" : (: ask_me, "jiedao" :),
		"��"   : (: ask_me, "jiedao" :),
		"����" : (: ask_me, "chanzhang" :),
		"��"   : (: ask_me, "chanzhang" :),
		"���" : (: ask_me, "qimeigun" :),
		"��"   : (: ask_me, "qimeigun" :),
		"Ƥ��" : (: ask_me, "changbian" :),
		"��"   : (: ask_me, "changbian" :),
	]));
	set("wuqi_count", 25);

	create_family("��������", 21, "����");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"whip/whip")->wield();
}

string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( present(name, this_player()) )
		return RANK_D->query_respect(this_player()) +"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";
	if (query("wuqi_count") < 1)
		return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";
	if (name == "changjian") 
		ob = new(WEAPON_DIR + "sword/" + name);
	if (name == "jiedao") 
		ob = new(WEAPON_DIR + "blade/" + name);
	if (name == "chanzhang") 
		ob = new(WEAPON_DIR + "staff/" + name);
	if (name == "changbian") 
		ob = new(WEAPON_DIR + name);
	if (name == "qimeigun") 
		ob = new(WEAPON_DIR + name);
	ob->move(this_player());
	add("wuqi_count", -1);
	message_vision("������$Nһ��"+ob->query("name")+"��\n",this_player());
	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ��ɱ�����顣";
}
#include "/kungfu/class/nanshaolin/fang.h";
