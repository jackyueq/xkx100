// Room: /d/gumu/lingwu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIC"������"NOR);
	set("long", @LONG
�˵ع������Ӵ�������֮�á����Ͻ��м������ţ�����������Ů��
�ڱ�Ŀ���򡣶���ʯ������һ��͹�𣬿��Ų�������(wall), �������
��һ�����ݣ�����Щ�Źֵ�ͼ��(ground), ������һЩ��Ůͼ��(top)��
LONG	);
	set("exits", ([
		"north" : __DIR__"mudao23",
	]));
	set("item_desc", ([
		"top"    : HIC "\t��Ů�����ڿգ���ң�������ΰٱ䡣\n"NOR,
		"wall"   : HIC "\t�ڹ��ķ�...��Ĺ�ӵܿ���ϰ�ڴˡ�\n"NOR,
		"ground" : HIC "\t��ת��Ų֮��...��Ĺ�ӵܿ���ϰ�ڴˡ�\n"NOR,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -30);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_lingwu", "lingwu");
	add_action("do_lingwu", "think");
}

int do_lingwu(string arg)
{
	mapping fam;
	object me=this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("dodge", 1);
	c_exp=me->query("combat_exp");
	if ( !arg ) 
		return notify_fail("��Ҫ��������������\n");
	c_exp=me->query("combat_exp");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("��Ѿ���ֲ�ʶһ��������ɶ��\n");
	if (arg == "top")
	{
		message_vision(HIY"$N��ʼ���Ӷ�����Ůͼ�Ρ�\n"NOR, me);
		if ((int)me->query("jing") < 25)
			return notify_fail("��һ���������������Թ��ȣ�����Ϣһ���ˡ�\n");
		me->receive_damage("jing", 25);
		if ((int)me->query_skill("force", 1) < 30)
		{
			message_vision(HIM "$N������Ůͼ�ο�ʼ��Ѫ��ӿ��Ŀ��ֱ���������������֮�⡣\n"NOR, me);
			write(HIR"�㶨��������������ͼ�������ٿ�Ϊ�\n"NOR);
			message_vision(HIR"$N��Ȼҡ������������������Ѫ��\n"NOR, me);
			me->receive_wound("qi", 10);
			me->unconcious();
			return 1;
		}
		if ((int)me->query_skill("unarmed", 1) < 30 )
			return notify_fail("������ƽ��������Щ��Ůͼ��ȴ�������а������ڡ�\n");
		if (me->query_skill("meinv-quan", 1) >= 1)
			return notify_fail("����ѧ������Ůȭ��Ҫ����һ����ֻ�ܿ��Լ��ڼ���ϰ��\n");
		write(HIY"�㾲����ϰ���ϵ���Ů���Σ����򵽹�Ĺ����Ůȭ���ľ������ڣ���ʱé���ٿ���\n"NOR);
		me->improve_skill("meinv-quan", 10);
		write(HIR "��ϲ����λ" + RANK_D->query_respect(me)+"�����Ѿ�ѧ����Ůȭ���ˡ�\n"NOR);
		return 1;
	}
	if (arg == "wall")
	{
		c_skill=(int)me->query_skill("force", 1);
		if (c_skill > 50)
			return notify_fail("ʯ�������������ģ����޷������ʲô�¶�����\n");
		if ((int)me->query("jing") < 20 )
			return notify_fail("����ú��ۣ�����˯����\n");
		me->receive_damage("jing", 5 + random(15));
		write("�㾲����ϰʯ�ڵ��ؼ������ڹ��ķ���Щ����\n");
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")));
		return 1;
	}
	if ( arg =="ground" )
	{
		c_skill=(int)me->query_skill("parry", 1);
		if (c_skill > 50)
			return notify_fail("����ŵ�����ϰһ�ᣬֻ���������Ѿ������ء�\n");
		if ((int)me->query("jing") < 20)
			return notify_fail("��һ���������������Թ��ȣ�����Ϣһ���ˡ�\n");
		me->receive_damage("jing",5 + random(15));
		write("��ģ�µ��ϵ�ͼ���������ݣ���ϰ�м����㡣\n");
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("parry", random(me->query("int")));
		return 1;
	}
	return notify_fail("���޷���������������\n");
}

