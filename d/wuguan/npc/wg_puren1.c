
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "pu ren", "puren","ren" }) );
	set("gender", "����" );
	set("age", 25);
	set("int", 28);
	set("long","���Ǹ����˴��������ˣ�������ת���Ĵ�������ͣ,������ʲô��\n");
	set("attitude", "peaceful");
	set("combat_exp",10000+random(5000));
	set("chat_chance", 3);
	set("chat_msg", ({
		"����ͻȻ˵��: ��Ժ����Ҫ���֣���ү��Ϊ�˷����ء�\n",
		"���۵�����˵: �ں�Ժ�����кö�ô�����\n",
	}));
	set("inquiry", ([
		"����" : "��ȥ����ү�Ӱɣ�\n",
		"����" : "��ȥ����ү�Ӱɣ�\n",
		"�ô�" : "�ҿɲ��������.\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
