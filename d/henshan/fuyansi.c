// Room: /d/henshan/fuyansi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ϊ�������滳�õĵ����������ڴ˺�������š�ɽ������
����·�Ժ�����ǵ���д�գ�����������������ɲ���������������
�����䣬��ɫ���š�ɽ��ǽɽ�й�������(zi)�������Զ���������ɱ档 
����ʯ����һ����(lian)���ּ�Բ���ת����¶���档
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu9",
           "westup"     : __DIR__"sansheng",
           "northdown"  : __DIR__"shanlu8",
        ]));
        set("item_desc", ([
            "zi":
"\n
�������з��  �������ߴ�����
ʯ·���������  ɮ�����м�����
��յ��������  �����ɼ������
�����Ϸ����ϴ�  ��̦��޺Զ���
\n",
            "lian":
"\n
     ��      ��
     ��      ��
     Ϊ      ��
     ��      ��
     ɽ      ��
     ��      ��
     һ      ��
     ��      ��
     ɲ      ��
\n",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1070);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
