// /d/city/feixingqi.c

#include <ansi.h>;
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "��������");
	set ("long", @LONG
�����Ƿ������ң�����������һ���񻨺�ľ�����̣����顰�����
񷡱���֣���������һЩս����ǽ�϶���һ��Сľ�� (ban)���ú�����
�߹�������Ϸ�淨��
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/flyer" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 21);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			������

����[��ʼ��Ϸ]����������
������Ϸ��join����������
��ʼ��Ϸ��start
������Ϸ��reset qi

����[��Ϸ����]����������
��ҡ���ӣ�toss
�鿴�����view
�ƶ����ӣ�move a|b|c|d
�ߴ���ң�next

����[��Ϸ����]����������
    �����壬��Ҵ�С�Ͷ�����������Ӿ��ǣ���������������ɣ���
��Ҳ���ö�˵�˰ɣ�\n";
}
