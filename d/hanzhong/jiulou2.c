// jiulou2.c
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ�������
�Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������
ֻ�����Ļ�̹��������ȫ�������Ļ�ɳ����֮���ϵĻ���������Ƹ�
�ǺƵ�����¥��ǽ�Ϲ���һ������(paizi)��
LONG
        );
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));

	set("coor/x", -3150);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
