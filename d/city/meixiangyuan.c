// Room: /city/meixiangyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
Ժ�е�׺����ɽʯ��������ǽ����һ��Ž���һ���������ġ�����
��һ��������һ����Ի������¥������������ʮ��÷��ֲ�š�ɽʯ��
��һ�ء������������鵰�֣�ϸ�׻��ۣ��и�һͤ��Ի�ҷ硣
LONG );
	set("no_fight", 1);
	set("item_desc", ([
		"north" : "��ϡ���Կ�����Ů�������档\n",
	]));
	set("objects", ([
		__DIR__"npc/changxiang" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"beiliuxiang",
		"north" : __DIR__"waifang",
	]));
	set("coor/x", 41);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	string time = NATURE_D->game_time();
	string money, msg;
	if ( objectp( ob = present( "chang xiang", environment(me) ) ) 
		&& living( ob ) )
	{
		if ( dir == "north" )
		{
			if( (strsrch(time, "��ʱ") >= 0) || (strsrch(time, "��ʱ") >= 0) || (strsrch(time, "��ʱ") >= 0) || (strsrch(time, "��ʱ") >= 0)) 
			{
				message_vision("������ס��$N˵����������С������Ϣ�أ����Ժ������ɰɡ���\n", me);
				return notify_fail( "�㱻������ס��ȥ·��\n" );
			}
			if ( random(2) || me->query_temp( "chang_block" ) )
			{
				message_vision("������ס��$N˵����������С�㲻���ͣ���ذɡ���\n", me);
				me->set_temp("chang_block", 1);
				remove_call_out("chang_dest");
				call_out("chang_dest", 1, me);
				return notify_fail("�㱻������ס��ȥ·��\n");
			}
		}
		if ( dir == "west" && me->query("lu_sing") )
		{
			money = chinese_number ( 8 + 2 * me->query("lu_sing") );
			msg = sprintf("%s%s%s%s%s", "��������㣺������С��", 
				chinese_number( me->query("lu_sing") ), 
				"�����ӣ�һ����", money, "�����ӡ�\n");
			write( msg );
			return notify_fail("�㱻������ס��ȥ·��\n");
		}
	}
	return ::valid_leave(me, dir);
}
void chang_dest(object me)
{
	if ( me->query_temp("chang_block") )
		me->delete_temp("chang_block");
}
