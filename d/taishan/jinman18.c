// Room: /d/taishan/man18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ʮ����");
	set("long", @LONG
�����ڲ�������ʮ�����ϣ����ȷ����Ӻ����ꡣ�����ǹ�ͺ����
�ڣ��޴������ڷ���ա�ʮ���̵���ɽ�±����������͵���·��Ƕ���У�
ԶԶ��ȥ��ǡ���������ݡ���ͷ�������������ϣ����ڽ��¡���ͷ����
���Ż���Զ�ء�̩ɽ֮��ΰ������ʮ���̣�̩ɽ֮׳���������ʵ��У� 
LONG );
	set("exits", ([
		"northup"   : __DIR__"shengxian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 740);
	set("coor/z", 170);
	setup();
	replace_program(ROOM);
}
