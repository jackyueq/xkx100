// tai.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",CYN "����̨" NOR);
	set("long", 
"���ǹ����"+RED "ǰ��" NOR+"�������֮���ˡ���ǰ��һ���߸ߵ�"+CYN "ʯ̨" NOR+"������
��գ�����Ũ������һ�㣬�����ƻã�"+HIW "����" NOR+"��������"+BLU "��Ԩ" NOR+"��Զ��������
��ʶ��"+HIR "�������" NOR+"����Ŀ��ȥ�������ɼ���ǰ֮�أ�������ѹ������ݣ�
��"HIG"��������"NOR"��Ȼ������翣����������ɼ�........\n"
BLU "        ����������Ϥ��һ�У���ļ����ƺ��ֱ������ˣ�������\n"
"    ����������������.................\n\n" NOR
);
	set("no_fight", 1);
	set("exits", ([ 
		"west" : __DIR__"dadian",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	object ob;
	if( interactive(ob = this_player())  )
	{
		remove_call_out("do_string");
		call_out("do_string",20,ob);
	}
}
int do_string(object ob)
{
	if( !ob || environment(ob) != this_object() ) return 0;
	write(BLU "    һ�������������˵��������������ڤ�����õ��ڴ���ǰ��һ�����ϣ�\n����ȥ��������������Ϊ�"+RED "�в����������ڳ�����ɫ֮��......\n\n" NOR);
	ob->unconcious();
	return 1;
}
