// pmchang.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��һ���ݵؾ��ǹ��������˵������ˡ������Ŀռ���������ڶ�
����ʹ����Ϊ��һ���æ�ļ���غ��г���һ��һ�ȵ�ˤ�ӱ���������
��Ҳ��������С�
LONG
        );
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/niu" : 1,
                    __DIR__"npc/yang" : 1,
                    __DIR__"npc/chen" : 1,
        ]));

        set("exits", ([
            "north" : __DIR__"shop",
            "west" : __DIR__"road",
            "southup" : __DIR__"caochang",
            "east" : __DIR__"caoyuan2",
            "southwest" : __DIR__"shuijing",
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
