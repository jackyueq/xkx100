// shantong.c ��ɽɽ��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
������ȫ��̿�ɽ��ʦ���������˾��޵�ɽ���������󣬵�
���沼�õú����£�����˼ҵĿ���һ���������Ϲ���һ����
(hua)�����β輸���ܾ��¡�
LONG
        );
        set("exits", ([
                "out" : __DIR__"xiaolu12",
        ]));
        set("item_desc", ([
        "hua": "������һ�������ʿ�ı�Ӱ��������ʲô��ò��������һ��ָ�죬������
�š�"+MAG"��������"NOR+"���������֡�\n"
        ]) );

        set("objects", ([
                CLASS_D("quanzhen")+"/wang" : 1,
        ]));

	set("coor/x", -2670);
	set("coor/y", 130);
	set("coor/z", 150);
	setup();
        replace_program(ROOM);
}