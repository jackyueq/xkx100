// road2.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
˵��·����ʵ���˲Ų�ԭ���߹����µĺۼ����쳤�վþͽ����г��ˡ�
��ֻ�����˲��������ﶨ���Ѿã����Կ�������������ԭʼ�ĵ�·������
������һ��С���
LONG);
        
        set("exits", ([
            "southwest" : __DIR__"road1",
            "north" : __DIR__"room-ji",
            "northeast" : __DIR__"caoyuan6",
            
        ]));

         set("objects", ([
                    __DIR__"npc/bird" : 1

        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
