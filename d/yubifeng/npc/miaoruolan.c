// miaoruolan.c ������

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "miao ruolan", "ruolan", "miao" }) );
	set("gender", "Ů��");
	set("age", 17);
	set("long","�������µ�һ���֣�����������޵��֡��ġ���������˷�֮Ů��ֻ����С�ҽ̣���ϰ�书��\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 34);
	set("combat_exp", 2000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"���������ĵص��������Ǹ�������С�к�����Ҳ��֪��ô���ˣ�\n",
		"��������������ü��������ô��û��ɽ��\n",
        }) );

	setup();
	carry_object(CLOTH_DIR"diaopi")->wear();
}
