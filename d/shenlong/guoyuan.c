// /d/shenlong/guoyuan.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һƬ��԰���ֵ���һЩˮ������ƻ������ͷ��ɽ髡����ӡ���
�ӡ�÷�ӵȣ��е��ѵ����ջ�ʱ�ڣ�֦ͷ�ѱ���ʵѹ�������������ģ�
��һ��֦ͷһ��һ���ģ����˿���ֱ����ˮ�����桢�����ƺ�����ũ�
������ɽ�𣬶�����һ��ɽ�ڡ�
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"shanqiu",
	]));
	set("objects", ([
		FRUIT_DIR"apple" : random(2),
		FRUIT_DIR"lizi" : random(2),
		FRUIT_DIR"taozi" : random(2),
		FRUIT_DIR"xingzi" : random(2),
		FRUIT_DIR"yangmei" : random(2),
	]));
	set("snaketype", ({"jinhuan"}));
	setup();
}

#include "snakeroom.h";
