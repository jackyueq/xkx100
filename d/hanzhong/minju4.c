// minju4.c ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���������һ�����Ϳ����ݽǴ��С���ض�������ʳ�����ó�����
����ճ�ȷʵ������������һλ������Ц�����ؿ����Լ��Ļ�����
Ҳ������������������ֲ����ˡ�
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"guchang",
        ]));

        set("objects", ([
                __DIR__"npc/cunmin" : 1,
        ]));
	set("coor/x", -3180);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}