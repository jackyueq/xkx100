// shop.c ������С�� 

inherit ROOM;

void create()
{
        set("short", "������С��");
        set("long", @LONG
�������������ƾɣ��ƺ���ú����˾�û����������������ߵ��ǹ�
�˲��ٶ�����ţƤ������ȵȣ����������Ǹ�С��Ʒ�㡣
LONG);
        set("exits", ([            
            "south" : __DIR__"pmchang",
            "east" : __DIR__"road1",
            "northwest" : __DIR__"sroom",
            "southeast" : __DIR__"caoyuan3",
        ]));        

        set("objects", ([
                    __DIR__"npc/dealer" : 1,
                    "/d/xingxiu/npc/trader" : 2
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
