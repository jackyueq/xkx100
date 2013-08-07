// NPC yupopo.c
// modified by rocwood

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name("������", ({ "yu popo", "yu", "popo" }));
	set("long",
		"���ǡ����չ�������Ų�����첿�����졣
������ͯ�Ѷ��꣬����������������˪��\n");
	set("title", "���չ���첿����");
	set("gender", "Ů��");
	set("class", "dancer");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("tianyu-qijian",100);
	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);
	map_skill("force", "bahuang-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");
	create_family("���չ�",2,"����");
	set("inquiry", ([
		"���չ�" : (: ask_me :),
		"��ʦ"   : (: ask_me :),
	]));
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}

void die()
{
	message("vision", HIW"\n������̾�������������ˣ�û�뵽��������ס���ɽ����ߣ�������Ҳ����ȥ����\n"NOR,"/d/lingjiu/jian");
	message("vision", HIW"�����ŻӶ�������ֻ������ƹ����һ������ڴֵ������϶ϳ������ء�\n"NOR,"/d/lingjiu/jian");
//	message_vision("$N�ҽ�һ�������ˣ�\n", this_object());
	::die();
}
string ask_me()
{
	object ob=this_player(),room;
	if(!( room = find_object("/d/lingjiu/xianchou")) )
		room = load_object("/d/lingjiu/xianchou");
	if (!(string)ob->query("family/family_name"))
	{
		if ((string)ob->query("gender")=="Ů��")
		{
			message_vision("�����ų���$N΢Ц˵����������ʦ�İɣ��������ȥ��\n",ob);
			message_vision("�����ų���һ����$Nֻ����һ���紵��������������ɽ������ȥ��\n",ob);
			ob->move(room);
			return "���չ��Ľ�����ϣ���ˡ�\n";
		} else return "�޳ܼ�ͽ���������չ��кξ��ģ�\n";
	}
	if ((string)ob->query("family/family_name")=="���չ�")
	{
		message_vision("�����ų���$N���ͷ��΢΢Ц��Ц��\n",ob);
		return "��λ���չ����������ˡ�\n";
	}
	return  "���������֮���������ɽ��������չ�������أ�";
}

