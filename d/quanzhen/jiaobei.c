// jiaobei.c �̱�
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�̱�");
        set("long", @LONG
������ȫ��̵Ḻ̌����ڵأ�·������һ���(bei)��������
�߾������������ĵ�����������--ȫ��̵Ĵ����ˡ�������һ��ʯ
�ף���֪��ͨ�������������ɽ��·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ����������
������������������
������������ȫ����
������������������
�������������桡��
������������������
�������������š���
������������������
�������������̡���
������������������
������������������
\n"NOR
        ]) );
        set("objects",([
                CLASS_D("quanzhen")+"/zhao" : 1,
        ]));

	set("coor/x", -3140);
	set("coor/y", 110);
	set("coor/z", 160);
	setup();
        replace_program(ROOM);
}