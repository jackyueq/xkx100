//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "�ջ���");
	set ("long","���Ǿջ�ʢ��ʱ�ڣ�����ڷ��˸���������ջ����ƾ���"HIY"��ʤ����
��ҩ���ƺ��ᡢ����֪�����ۻơ����ȸ�����յ��ݺ���"NOR"���׾���"HIW"��
�°ס���ĵ�������ࡢ�����硢һ��ѩ���������¡�̫Һ��"NOR"���Ͼ���
"MAG"�̽�ϼ��˫���ࡢ��ϼ篡�����������ϼ��������̡�������"NOR"�������
"HIR"���˺졢���ƺ졢���������ܽ�ء���֬�㡢����֦���׶���"NOR"������ɫ
����"HIM"���Ц������š��һ��ա���ʩ�ۡ�ʤ��ҡ���¥��"NOR"��ֻ��ϧû��
"HIG"�̾�"NOR"��\n");
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
		__DIR__"npc/lingshuanghua" : 1,
                "/clone/medicine/vegetable/jugeng" : random(2),
	]));

	set("exits", ([ 
		"east" : __DIR__"hzjie3",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
