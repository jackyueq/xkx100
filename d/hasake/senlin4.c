// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	int a1,a2,a3,a4;
	a1 = 1+random(4);
	a2 = 1+random(4);
	a3 = 1+random(4);
	if (a1 != 1 && a2!=1 && a3!=1) a4=1;
	else a4 = 1+random(4);
       set("short","��Ҷ��");
       set("long", @LONG
���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ
�����롣��������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ��
���������������߱��Ǵ��ԭ�������ڵĹ������������������������
�����ţ���Ȼ��ʧ�˵�·��
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+a1,
             "west"  : __DIR__"senlin"+a2,
             "south" : __DIR__"senlin"+a3,
             "north" : __DIR__"senlin"+a4,        
        ]));
        
        set("objects", ([
                         __DIR__"npc/toulang" : 1,
        ]));

        set("outdoors", "hasake");
        setup();
           
}