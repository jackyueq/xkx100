// room-ji1.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
С���г����ª�����������࣬��ɨ��ǬǬ������һλ����������ձ
������������ꡣ���ܷ���Щ����м��С��ľ���ϸ��˼����ߺ���Ʈ
���������˵�������
LONG
        );
        set("exits", ([
            
            "out" : __DIR__"room-ji",
        ]));
        
        set("objects", ([
                    __DIR__"npc/ji" : 1,
      //              __DIR__"npc/li" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
