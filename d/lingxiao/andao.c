// Room: /d/lingxiao/andao.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�������ǵİ�������������������ʲô�˳��������ͨ����
��ǽ�ϲ��ŵļ��������ɢ�����Ĺ�â�£����Կ���������һ���飬��
֪�����ĸ����Ĺ��������ġ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"out"       : __DIR__"muwu",
		"northdown" : __DIR__"didi",
	]));
	set("objects", ([
		BOOK_DIR+"sword_book3" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}

