// shishi1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʯͷ���ɵķ��䣬��Ϊ�þ�û����������ɢ����һЩ����
�ŵ���ζ�������е������Կ�����˿�ͳ漣��
LONG );
	set("exits", ([
		"east" : __DIR__"shiji1",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}