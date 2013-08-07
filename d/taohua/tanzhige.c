// Room: /d/taohua/tanzhige.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��ָ��");
	set("long", @LONG
����һ�������ȴ���С��͸�����죬���Կ�������ĵ�ָ�塣��
����ȥ���ǰ������ϵĴ󺣣������ϰ�Ÿ���ɷ�����ȥ�����ǡ������
��ɡ������������һ����Ƥ�ˣ���������Ѩλ(xuedao)�����̲�ס
��ָ��Ѩ����(tan)ȥ��
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_tan", "tan");
}
int do_tan(string arg)
{       
        mapping fam;
	object me = this_player();
	if (arg != "xuedao")
		return notify_fail("���ʲô�㰡�㣿������㰡�㣿\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "�һ���")
		return notify_fail("��Ǳ������ӣ������ڴ�������\n");

	if ( (int)me->query_skill("finger", 1) > 100)
		return notify_fail("����ָ����Ƥ�����ϵ�ȥ��������Ƥ��̫���ˣ�û���������ָ����\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write( "����ָ����Ƥ�����ϵ�ȥ�����һ������Ҳû�У�������̫���ˣ�\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("finger", me->query("int"));
	write("����ָ����Ƥ�����ϵ�Ѩ����ȥ�����˸����ţ�\n");
	return 1;
}