// /d/shenlong/yaofang ҩ��
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "ҩ��");
        set("long", @LONG
������������ҩ������ǽ���������ӣ������з���������в�ҩ��
½�������������ϵ�����ץҩ�����Ρ�����½�������������ͷ��
���£��������ҪһЩ�ۻ��Ա��⵺�ϵĶ������ţ�ֻ��ȥ����С���ˡ�
LONG
        );
	set("exits", ([
                "north" : __DIR__"zhulin1",
        ]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

