// Room: /d/tiezhang/hxfang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���Ǵ��������һ��С���䣬��ȻҲ����ʯ���ɣ������õķǳ���
�ʡ��ı��ù�̺��ס����¶һ��ʯ�ڵĺۼ�������תȦ�ڷ���һЩ���ӣ�
�������ź�����棬����ȥһ�������ʡ������ǰ�����������ճ���
��ĵط�������ͨ���Ժ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"hhyuan1",
		"south" : __DIR__"wztang",
        ]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}