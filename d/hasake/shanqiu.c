// shanqiu.c Сɽ��

inherit ROOM;

void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
�����ǲ�ԭ��ɭ�ֵķֽ��ߣ��������Կ����������Ƶ���ɽɽ���ʹ�
����һֱ�����ȥ����Ҷ�֣��������Կ��������������������������
�����������˵Ļ��
LONG);        
        set("exits", ([
            "eastdown" : __DIR__"road",
            "south" : __DIR__"caoyuan9",
            "north" : __DIR__"caoyuan9",
            "westdown" : __DIR__"senlin1",
        ]));

        set("objects", ([
                         __DIR__"npc/bird" : 1,
                         __DIR__"npc/supu" : 1,
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
