// yebee.c ���

inherit NPC;
#include <ansi.h>;
void create()
{
	set_name(HIY"���"NOR, ({ "yu bee", "bee" }) );
	set("race", "����");
	set("subrace", "�ɳ�");
	seteuid(getuid());
	set("age", 1);
	set("long", "����һȺ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬\n");
	set("attitude", "peaceful");
	set("no_train", 1);
	set("combat_exp", 500);
	set("chat_chance", 3);
	set("chat_msg", ({
		"����������˵��������ͣ��\n",
		"�����ٵ���������������Ҫ����һ�ڡ�������Ҫ�������һɲ���ַɿ��ˡ�\n",
		"��������˷ɹ���������ͷ��ת��һȦ���ַ����ˡ�\n",
	}) );
	set_temp("apply/attack", 200);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
	setup();
}
void init()
{
	::init();
	if(strsrch(file_name(environment(this_object())),"baihuagu") < 0)
	{
		write("���������ת��һȦ���ɻذٻ���ȥ�ˡ�\n");
		destruct(this_object());
	}
}
