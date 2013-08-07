// medicine5.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_kan", "watch");
	add_action("do_kan", "kan");
}

void create()
{
	set_name(HIY"��˼��ǧ��"NOR,({"qianjin fang","qianjingfang","fang"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"\n����һ������˼��ǧ�𷽡�������Ժúÿ���(watch)��\n");
		set("value", 50);
		set("material", "paper");
	}
	setup();
}
int do_kan(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("medicine", 1);

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return 0;

	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if ( !me->query_skill("medicine", 1) )
	{
		write("����ҽ�顣��һ�ϲ�ͨ����ɶ�ÿ��ģ�\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) )
	{
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
	write(HIR"                   ���Ƶ��ھ���\n");
	write(YEL" ��������ҩ�ط���\n\n");
		write(HIG"��ҩ           ���������ء�Ѫ��\n");
	if (lvl >= 10)
		write("������           �����������ӣ��չ�\n");
	if (lvl >= 20)
		write("����ɢ           �Ͷ�����Ҷ���չ�\n");
	if (lvl >= 30)
		write("�׻�������       ���ǡ���ɽѩ�������ߡ�����\n");
	if (lvl >= 40)
		write("�����ܵ���       �ܵ������ơ������ûҩ\n");
	if (lvl >= 50)
		write("���������       ��ޱ��ûҩ����֥����֬\n");
	if (lvl >= 60)
		write("С����           ɣҶ�����顢��ɽѩ����޽��\n");
	if (lvl >= 70)
		write("�ٲݵ�           ��ɽ�ס��ʲݡ��غ컨\n");
	if (lvl >= 80)
		write("����۾���       ��ɽѩ�����غ컨����Ҷ\n");
	if (lvl >= 90)
		write("��������ɢ       �����ڡ���ɽ�ס����ߡ����硢�չ�\n");
	if (lvl >= 100)
		write("��ʯ�񶴵�       ��̥�����硢�ܵ�����ɽѩ��\n");
	if (lvl >= 110)
		write("��ת������       ţ�ơ����ɡ������ӡ���Ҷ\n");
	if (lvl >= 120)
		write("�Ż���¶��       ��ɽѩ�����ʲݡ��һ��ꡢ��Ҷ\n");
	if (lvl >= 130)
		write("��¶����ɢ       ��Ҷ�����顢��ޱ��������\n");
	if (lvl >= 140)
		write("���Ʊ�����       ��ơ��ٻơ��ۻơ���֬\n");
	if (lvl >= 150)
		write("�󻹵�           ��Ҷ�����顢��ɽѩ����޽��\n");
	if (lvl >= 160)
		write("��������         �˲Ρ����ߡ���֥��¹�ס������ڡ���֬���ܵ������ߡ�����\n");
		write("\n"NOR);
        return 1;
}
