// Room: /d/lingxiao/shiya.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","ʯ��");
	set("long",@LONG
ת��ɽ����������ʯ�໥��������һ���ܷ��ʯ�¡�����˷��
�������ȴ¯�����ܣ���ľ����������˿˿�������ζ����������Ѳ
ɽ���ˣ���������ܷ������Ա��и�С�꣬ƣ�ۼ���ʱ������������
����Ϣ��
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"bar", 
		"westdown" : __DIR__"sroad3",
		"northup"  : __DIR__"sroad4",
	]));
	set("objects",([ /* sizeof() == 1 */
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

