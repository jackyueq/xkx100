// road1.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
˵��·����ʵ���˲Ų�ԭ���߹����µĺۼ����쳤�վþͽ����г��ˡ�
��ֻ�����˲��������ﶨ���Ѿã����Կ�������������ԭʼ�ĵ�·��
LONG
        );

        
        set("exits", ([
            "northeast" : __DIR__"road2",
            "west" : __DIR__"shop",
            "north" : __DIR__"caoyuan4",
            "southdown" : __DIR__"caoyuan3",
            
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
