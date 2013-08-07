// Room: /d/taishan/nantian.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ʮ���̣��㵽�����š��������ֳơ������š�����Ϊ��¥ʽ
�������ű���һ������(lian)���ϸ�Ħ�ո���̩ɽ������ڴ�������
�︽��ɽ�£�Ⱥɽ�����أ����������ƣ���ؿ������޿���״����
�����������߾�����֣������߱����¹۷壬���������ǵ���ʶ�֮·��
LONG );
	set("exits", ([
		"west"      : __DIR__"yueguan",
		"eastup"    : __DIR__"tianjie",
		"northup"   : __DIR__"yuhuang",
		"southdown" : __DIR__"jin18",
	]));
	set("item_desc", ([
		"lian" : "
�űپ�������������ʤ��  �׳��򼶣�����ǧ�����\n",
	]));
	set("objects",([
		CLASS_D("taishan")+"/tianbai" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}

