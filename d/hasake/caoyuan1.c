// caoyuan1.c ��ԭ

inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣�ϱߺ����߶��кö�������
�����Կ���ɳĮ�ı�Ե��
LONG);
        set("exits", ([
            "northeast" : __DIR__"caoyuan",
            "west" : __DIR__"caochang",
            "south" : __DIR__"majiu",
            "north" : __DIR__"caoyuan2",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 2
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
