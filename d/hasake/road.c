// road1.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����С·�ǵ����������ȥ���������ʱ�߳����ģ��������߾͵���ԭ
��Ե������ɭ���ˡ�ż����������Զ������Ұ�޵ĺ������㻹�ǿ��ȥ�ɡ�
LONG
        );

        
        set("exits", ([
            "westup" : __DIR__"shanqiu",
            "east" : __DIR__"pmchang",
            
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
