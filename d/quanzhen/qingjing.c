// qingjing.c �徻��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�徻��");
        set("long", @LONG
������ȫ������֮ĩ��Ҳ��Ψһ��Ů�����ﲻ���ľ��ҡ��ⷿ��
����������������λʦ�ֵ����Ҵ���ͬ�������۵���һ�����ۣ���
������һ������ͷ��������ͷ�ɲ�������������˵ģ��ǵ���������
���ﲻ��Ϊͽʱ������һ������ͼ����������˼��˵������̣��õ�
Ϊ�����ﲻ������ʦ�����ͽ��������ͼ�������Լ��ĵ����ϡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"nairongdian",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/sun" : 1,
        ]));

	set("coor/x", -2780);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}