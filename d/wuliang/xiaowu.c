// Room: /wuliang/xiaowu.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ľͷС�ݡ����г����ª�������������У�������Ȼ��
�����������˵����ڣ�ֻ�ǿ���������޾ִ�֮�У�
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"west"       : __DIR__"huayuan",
	]));
	set("coor/x", -70970);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}