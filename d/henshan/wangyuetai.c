// Room: /d/henshan/wangyuetai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
����̨��ף�ڵ��һ���ʾ�ʯ��ÿ��ҹ������µ��գ��������̱�
�֣�����������ԣ�������ɫ����ӳ�Ͱ���Ⱥ�塣��ʱ "��Ȼ�����
��ʮ���壬����������У�ʼ���·��޴���Ҳ��" ǰ�������ʫ: �˼�
�����ѽԾ����˵������δ�͡�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"    : __DIR__"zhurongdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -980);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
