// Room: /d/songshan/qianting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "ǰͥ");
	set("long", @LONG
�����Ǿ�����Ժɽ����ǰͥ��ͥԺ����ʯ�̵ء��Ű�ɭɭ��������
�����˼��ᡣ��������Ժ��������һЩ�Ͱ�С����
LONG );
	set("exits", ([
		"north"     : __DIR__"chanyuan",
		"southdown" : __DIR__"junjigate",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/shi" : 1,
		CLASS_D("songshan")+"/di" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 860);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
