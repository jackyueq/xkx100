// Room: /huanghe/bingcao.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ӫ��ˮ�����ϣ�ƽʱ�˼���������Ϊ����ɳĮ�ﳤ��һ
�������ҩ��----"����"����������˵����ҩ���ܽ�ٶ�������ż��
���������ֲݣ�����ɳĮ�ﳣ�ж����û����ΪΣ�ա�
LONG );
	set("exits", ([
		"southwest" : __DIR__"shixiazi",
		"northeast" : __DIR__"yinpanshui",
	]));
	set("objects", ([
		__DIR__"npc/wugong" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -21000);
	set("coor/y", 18000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}