// Room: /d/yanping/banyanting.c
// Date: Sep 28, 2002  Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
��ǧ�˰ٿ���Ȥ��Ȼ��ɽ��������գ�ʢ���������������
�ľ���ѭ�������۵�ʯ�׶��У�;��������ͤ���԰���ͤ��Ϊ��ʤ����
��ͤ���ϣ�����Σ᧣��������֣��������ң�����֮ʱ�ٲ����Ҷ���к
���£�ɷΪ׳�ۡ���ƽ�˾�֮һ�ġ����ҷ��١�(pu)����ָ�ˡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"gubao",
		"southdown" : __DIR__"3800kan",
	]));
        set("item_desc", ([
                "pu" : 
HIC"        �����ٲ�\n"HIY"                    ���(��)"NOR"
����һ���ɣ� ���Ʊ�ɽ�̡�
�������ʿ��� �������񴨡�\n"HIY"
                    �μ�(��)"NOR"
ɽ���о��ߣ� ľʳ�²�����
������ǧ�ߣ� ����佽ٻҡ�\n"HIY"
                    �⹧(��)"NOR"
���Ӵ�����ǧ�ߣ� ��������ʯ�ڶˡ�
�ٲ�������ɫ���� ѩ����׹���⺮��
�������������ݣ� �꺵���Ǻ�ˮǬ��
����Я�����˴��� ����ׯ�ӹ��̻���
\n",
        ]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
