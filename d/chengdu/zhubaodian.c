// Room: /d/chengdu/zhubaodian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "�鱦��");
        set("long", @LONG
�������ȫ�������ġ�л�ǡ��鱦�ꡣл�����鱦��һ���Ѿ�����
�ϰ������ʷ������ѡ���ϳˣ��������ɣ����������Ϊ��ٹ�������
������Ϊ�����������С�л�ǡ��鱦����һ����ݵ��������ſڹҵ�
������Ȼ��Щ���ˣ�ȴ��ʾ������ʷ���ƾá�
LONG	);
        set("exits", ([                
                "east" : __DIR__"beijie2",                
        ]));
        set("objects", ([
                __DIR__"npc/yunyan" : 1,
                __DIR__"npc/huoji" : 1,
        ]));
        set("coor/x", -8060);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 
