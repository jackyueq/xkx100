//Room: /d/dali/chahua8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��԰����");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰���ſڣ�������԰��ɫ��������ϲ���������߾ͽ�԰�ˣ�������һ
��ʯ������
LONG);
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "east"   : __DIR__"chahua7",
	    "west"   : __DIR__"yongdao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38960);
	set("coor/y", -69970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}