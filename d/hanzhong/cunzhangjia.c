// cunzhangjia.c �峤��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�峤��");
        set("long", @LONG
�����Ǵ峤�ļң�������ѷ���һЩ��ͷ������֮���ũ����
�ߣ���һЩ�Ǵ��д�����ﻵ�ˣ�������峤���޵ġ�����ǰ����
��ʮ���ʺ������������һЩ��ɵ�Ұζ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"guchang",
        ]));
        set("objects", ([
                __DIR__"npc/dibao" : 1,
        ]));
	set("coor/x", -3170);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}