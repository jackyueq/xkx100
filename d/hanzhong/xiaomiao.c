// xiaomiao.c ������
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ԭ�����书���е�������������Ϊ�ܾ�û�����ɹ���
�Ѿ����ò���������ү�Ľ���Ҳֻʣ���˰�أ�����ֻʣ��������
�ȣ������Ѿ�ȫ���¹��ˣ���������ƶ������ûؼ�ȥ����ȡů��
����ƽ����û�������ģ�ֻ��һЩ���ֺ��еĵ�Ʀ��å֮�������
�����˼ҡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"xijie",
        ]));

        set("objects", ([
                __DIR__"npc/dipi" : 1,
        ]));

	set("coor/x", -3160);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}