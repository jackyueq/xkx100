//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��һ��ʿ"NOR, ({ "chongyi jushi", "chongyi" }));
	set("title", "����ϰ�");
	set("nickname", HIW"����"HIY"�ޱ�"HIB"������"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 25);
	set("long","
��λ��һ�������Ǹ�����֮�ˣ�����ϲ���ţ������ڲ����
�������Ŀ���̸ʫ�ۻ���\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/jiangling/obj/jiuhuangb",
		"/d/jiangling/obj/babao",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

