// Room: /yangzhou/xichuntai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","����̨��¥");
	set("long",@LONG
����̨λ����������������������ңң��ԡ�Ǭ¡�Է����͢谽���
�ɾ�����̨���¡���ΪǬ¡ʢ��������ʮ�ľ�֮һ����˵���ڴ�ΪǬ¡
�ʵ�ף�٣�����������̨ף�١���
    ¥������������̨�����ң��������ڹң����鷨��׭����һ�壬
�Կ��������Ҹ�ӽ���ݵ�ʫ�ʺ͹Ŷ�ʮ��������������������ʮ��ֻ��
���������ҹ����ͷף��������ԡ�
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"down"   : __DIR__"xichuntai",
	]));
	set("objects", ([
		"/d/city/npc/lady1" : 1,
	]));
	set("coor/x", -60);
	set("coor/y", 100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
