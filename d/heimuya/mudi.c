// Room: /d/heimuya/mudi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "Ĺ��");
	set("long", @LONG
�����Ǻ�ľ��������̽��ڵ�Ĺ�ء�Ĺ�ص���Χ����һЩ�����Ļ�
�������ϵİ׻����ǵ�㡣�׻��м���һ�ߴ��ʯ�� (bei)������Ĺ��
�ɸɾ�������Ȼ�������˴�ɨ��
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
        	"west"      : __DIR__"grass1",
        ]));
	set("item_desc", ([
        	"bei": "������ţ����������������\n"
	]));
        set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}