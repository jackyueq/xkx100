// /d/shenlong/zhulin2 ����2
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����һƬ��ʵ�����֣����߰�������һ��С�ľͻᱻ���µ�֦��
�����ͷ�������ƺ�����΢��ɳɳ���������Ǻ��紵���ֺ����ǳ�����
����������е㲻�Ծ�������˵������ʲô��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"zhulin1",
		"north" : __DIR__"liangongfang",
	]));
	set("snaketype", ({"zsnake"}));

	setup();
}

#include "snakeroom.h";
