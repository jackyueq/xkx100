// Room: /d/wizard/wizard_jail.c
// Last modified by winder 2002/10/18

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������Ǳ���̶����ʦ�����������ϱ����ţ��������޴���������
�������ʦ���������ᷨ������Ȼ��������ʲôҲ���룬���Ǿ���
˼���ɡ�
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : "/d/death/god2",
	]));
	setup();
}

void init()
{
	object me = this_player();

	if(me->query("id") != "winder")
	{
		write(HIC"����"NOR
"������Ǳ���̶����ʦ�����������ϱ����ţ��������޴���������
�������ʦ���������ᷨ������Ȼ��������ʲôҲ���룬���Ǿ���
˼���ɡ�
    ����Ψһ�ĳ����� "HIW"south"NOR"��\n");
		me->set("startroom",base_name(environment(me)));
		add_action("block_cmd","",1);
	}
}

int block_cmd(string arg)
{
	if(arg != "l") return 1;
}

