// Room: /d/nanshaolin/jieluyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <login.h>
void create()
{
	set("short", MAG"����Ժ"NOR);
	set("long", @LONG
��������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����ҹһ�㣬
ÿ��������ǽ�ϣ���ȼ�ż�֦ţ�;��򡣵��Ϲ����Ž�ħΤ���·�����
һ����ˮţƤ�ޡ�������弰��������ִ�����ȡ�����վ���˻����䵶
��ִ��ɮ���������������ϵ�����������㣬���㲻���������⡣
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu4",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dadian" : 1,
		__DIR__"npc/zjseng" : 1,
		__DIR__"npc/slseng" : 1,
		__DIR__"npc/xiao-tong" : 1
	]));
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("coor/x", 1840);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
}

void init()
{	
	mapping fam;
	object ob;

	if( interactive(ob = this_player()) )
	{
//		if(wizardp(ob)) return;
		if( mapp(fam = ob->query("family")) &&
			fam["family_name"] == "��������" &&
			fam["generation"] <= 20 &&
			!ob->query("guilty") ) 
			return;
		message_vision(HIY"$Nһ������Ժ��...ֻ��������ȣ���ͬը�װ��ڴ������졣$N��������������Ҳվ����ס����һ����ͨһ������������\n\n"NOR,ob);
		ob->set("startroom", "/d/shaolin/jieluyuan");
		call_out("processing", 3, ob);
	}
}

void processing(object ob)
{
	mapping fam;

	if (!ob) return;
	write(HIW "\n�㶨�˶���̧ͷϸ����ֻ����ʮ���ֵ�ɮ�˽�������Χ������\n"
		"һƬѩ���ĵ���Ƶ����۶�����������ǰ���ĸ�̨�Ϸ���һ��\n"
		"̫ʦ�Σ����и�����λ�����ü����ɮ����ɫ���࣬Ŀ�侫�⣬\n"
		"�ݺݵص����㡣\n\n\n" NOR);
	if ( !(fam = ob->query("family")) || fam["family_name"] != "��������" )
	{
		message_vision(HIY "���һ����ȣ����ȴ󵨿�ͽ���ô����£����ڲ��죬�õ����\n�����������£������������С��˺�����Ϊ��ִ��ɮ�����ڣ�\n\n" NOR, ob);
		call_out("responsing", 3, ob, 3);
        }
	if ( (fam = ob->query("family")) && fam["family_name"] == "��������" ) 
	{
		if (ob->query("guilty") == 1)
			message_vision(HIY "���һ����ȣ�$N�������½������գ�ȴ����ɱ��Խ����������Ϊ��\n�۷���䣬�ܻ�����ǧ����������õ������ִ��ɮ�����ڣ�\n\n" NOR, ob);
		if (ob->query("guilty") == 3)
			message_vision(HIY"���һ����ȣ�$N�����»����������������������˵������룬\n���ô��˵أ����ڲ��죬�õ����ִ��ɮ�����ڣ�\n\n"NOR,ob);
		if (ob->query("guilty") == 2)
		{
			message_vision(HIY "��񲶢��$N���˰��ã�˵����$N����Ͷ����ƣ��������������ñ��ã�\n���������׽�ɱ�������˺�����������ɮ�ҵ����\n��ȥ�գ��´ζ������ģ�\n\n" NOR, ob);
			ob->delete("guilty");
			ob->set("startroom", START_ROOM);
			return;
		}
		call_out("responsing1", 3, ob, 3);
	}
}

void responsing(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "ɮ������Ӧ���������ڣ�\n" NOR, ob);
	i--;
	j = random(3);
	if (i == 0) 
	{	
		call_out("beating", 3, ob);
		return;
	}
	call_out("responsing", j, ob, i);
}

void responsing1(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "ɮ������Ӧ���������ڣ�\n" NOR, ob);
	i--;
	j = random(3);
	if (i == 0) 
	{	
		call_out("beating1", 3, ob);
		return;
	}
	call_out("responsing1", j, ob, i);

}
void beating(object ob)
{

	if (!ob) return;
	message_vision(HIY "\n\n���ȵ����������٣���$N����ɮ���Ѻ���£���ϴ�Ļڸģ�\n�����ͷţ���ͼԽ�������һ�ȣ�\n\n" NOR, ob);
	message_vision(HIR "ɮ����һӿ���ϣ��Ұ����£�$Nʹ�û��˹�ȥ......\n" NOR, ob);
	ob->delete("guilty");
	ob->move("/d/nanshaolin/jianyu");
	ob->unconcious();
}

void beating1(object ob)
{
	int i;
	object kao;

	if (!ob) return;
	i = 20 + ob->query("combat_exp") / 100000 * 10;
	if (i > 50) i = 50;
	ob->set("carry_count", i);
	message_vision(HIY "\n\n���ȵ����������٣���$N��ȥ�����ˮ" + chinese_number(i) + "Ͱ����ϴ�Ļڸģ�\n�����ͷţ���ͼ͵�������һ�ȣ�\n\n" NOR, ob);
	message_vision(HIR "ɮ����һӿ���ϣ��Ұ����£�$Nʹ�û��˹�ȥ......\n" NOR, ob);
	ob->delete("guilty");
	kao = new("/d/nanshaolin/obj/liao_kao");
	kao->move(ob);
        ob->unconcious();
	ob->move("/d/nanshaolin/houdian");
	ob->set("startroom", "/d/nanshaolin/houdian");
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if ( userp(me) && dir == "west" )
	{
		if( mapp(fam = me->query("family")) &&
			fam["family_name"] == "��������" &&
			fam["generation"] <= 20 && !me->query("guilty")) 
			return ::valid_leave(me, dir);
		else
			return notify_fail("���˵��: �󵨣��㻹�����ܣ�ִ��ɮ�����ڣ�\n");
	}

}
