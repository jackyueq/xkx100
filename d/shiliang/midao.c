// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ�������ɽ�����Ĵ����������ģ��㼱�ÿ������
��������(wall)�����ǻ��������̦������ֵ��������и���
��(string)������ϵ��һ����ʯͷ(stone)��
LONG
        );
	set("coor/x", 1600);
	set("coor/y", -1980);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_reach", "reach");
}
int do_reach(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg=="") return 0;
	if( arg=="stone")
	{
message_vision("$N����ȥץʯͷ�������ǲ�һ�㹻�ţ�Ҫ������һ��ͺ��ˡ�\n",me);
	}
	if( arg=="string")
	{
message_vision("$N����ȥץ�����������ǲ�һ�㹻�ţ�Ҫ������һ��ͺ��ˡ�\n",me);
	}
	return 1;
}
int do_climb(string arg)
{
	object me;
	me = this_player();
	if (!arg && (arg != "wall")&& (arg != "string"))
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg=="wall" )
	{
message_vision("$N�������˺ü��Σ����Ƕ���ʵ����̫������ôҲ�ϲ�ȥ��\n", me);
	}
	if( arg=="string" )
	{
		if(me->query_temp("hasjump"))
		{
			me->delete_temp("hasjump");
message_vision("$N˳�ų���������������������ɽ����\n", me);
message_vision("$N�������۾����·𻹲���Ӧ����Ĺ��ߣ������и�������ǰ��\n",me);
			me->move(__DIR__"jinshedong");
		}
	else return notify_fail("\n�㹻���š�\n");
	} 
	return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
	if (!arg && (arg != "stone") && (arg != "string"))
		return notify_fail("��Ҫ���Ƕ�����\n");
	message_vision("$N����һ�����������͵�һ����һ��ץס��ʯͷ��\n", me);
	message_vision("ֻ����µµһ�����죬ʯͷһ��������ͷ��$N���˼��ˡ�\n", me);
	me->set_temp("hasjump",1);
	return 1;
}
