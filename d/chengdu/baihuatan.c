// Room: /d/chengdu/baihuatan.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "�ٻ�̶");
	set("long", @LONG
̶��ƽ������һ�����λεľ��ӣ���ӳ�ź���������̶��ļ�Ƭ��
Ҷ���ָ�̶ˮ�����˼�����ɫ��
LONG	);
	set("outdoors","chengdu");
	set("exits", ([		
		"northeast" : __DIR__"path4",				
		"north"     : __DIR__"caotang",				
	]));
	set("objects" , ([
		__DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8090);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

