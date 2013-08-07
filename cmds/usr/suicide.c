// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int halt_suicide(object me);
private int slow_suicide(object me);
int sure1(string arg,object me,string skill,string pfm);
int sure2(string arg,object me,string skill,string lskill);
int scborn(object me,string arg);
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2);

int main(object me, string arg)
{
	object *inv;
	string *args;
	int i;
	
	seteuid(getuid());
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]))
		return notify_fail("�����ϻ��и�������أ��벻��Ҳ��ѽ��\n");
	}
	if( !arg )
		return notify_fail("��ɱ�����֣�����Ҫ��Զ����(-f)��������Ͷ̥(-r)��\n");
	args = explode(arg," ");
	if (args[0]!="-f" && args[0]!="-r")
		return notify_fail("��ɱ�����֣�����Ҫ��Զ����(-f)��������Ͷ̥(-r)��\n");
	if (args[0]=="-f")
	{
		write("�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n���������ȷ���Ļ��������������룺");
		input_to("check_password", 1, me, 1);
		return 1;
	}
	return scborn(me,implode(args[1..sizeof(args)-1]," "));
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n�����Ҫ��ɱ�ˣ������ʮ���ڲ���ڣ�����������ˡ�\n\n\n" NOR);
		me->set_temp("suicide_countdown", 8);
		me->start_busy( (: slow_suicide,me :),(: halt_suicide,me :));
	}
}
private int halt_suicide(object me)
{
	tell_object(me,"����������̶���̸Ц���������Ǵ�����Ѱ������ͷ��\n");
	me->delete_temp("suicide_countdown");
	return 1;
}
private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string id;

	stage = me->query_temp("suicide_countdown");
	link_ob = me->query_temp("link_ob");
	if( !link_ob || !stage ) return 0;
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( (stage-1)%5 == 0 || stage < 6)
			tell_object(me, HIR "�㻹�� " + (stage-1)*2 + " ���ʱ����Ժ��(halt)��\n" NOR);
		return 1;
	}


	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	id=geteuid(me);
	if (!id) id=getuid(me);
	link_ob->save();
	me->save();
	cp( link_ob->query_save_file() + SAVE_EXTENSION ,sprintf(DATA_DIR "suicide/login/%c/%s"+ SAVE_EXTENSION, id[0], id));
	cp(      me->query_save_file() + SAVE_EXTENSION ,sprintf(DATA_DIR "suicide/user/%c/%s" + SAVE_EXTENSION, id[0], id));
	rm( link_ob->query_save_file() + SAVE_EXTENSION );
	rm(      me->query_save_file() + SAVE_EXTENSION );
		write("�ðɣ�������:)��\n");
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
  message("channel:sys",HIR"��ϵͳ��Ƶ�����飺"+me->name()+"("+id+")��ɱ�ˡ�\n"NOR,users());
	destruct(link_ob);
	destruct(me);
	return 0;
}
int scborn(object me,string arg)
{
	int times;
	string skill,lskill,fskill,skill2,skill3;
	string pfm;
	int i;
	string *cant;
	mixed dir;
	string str;
	string temp;
	
	notify_fail("��û��ת����\n");
	if (!SCBORN_D->valid_scborn(me) && me->query("id")!="trya")
		return 0;
	times = SCBORN_D->query_scborn_times(me);
// һת Ӧ���� reborn(user,"taiji-quan","zhen"); ����taiji-quan��pfm zhen
// ��ת Ӧ���� reborn(user,"taiji-quan","literate"); ���� ��������
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-shengong"); ����
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-jian");
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-jian","huifeng-jian");
// ��ת Ӧ���� reborn(user);
	switch(times)
	{
		case 0:
			if (!arg) 
				return notify_fail("��һ��ת����ʽΪ��suicide -r �书 ����\n");
			if (sscanf(arg,"%s %s",skill,pfm)!=2)
				return notify_fail("��һ��ת����ʽΪ��suicide -r �书 ����\n");
			//����书
			if (!me->query_skill(skill))
				return notify_fail("�㲢��������书��\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("�㻹���ܱ���֪ʶ���ܡ�\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("�㻹���ܱ����ڹ���\n");
      //���pfm
			if (file_size(SKILL_D(skill+"/"+pfm+".c"))<0)
			{
				write(to_chinese(skill)+"��û��"+pfm+"��������÷�\n");
				write("�������书������ʹ����(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
			}
			if ( !me->query("perform/"+pfm) && !SCBORN_D->valid_perform(me,skill,pfm))
			{
				write("�㻹�޷�����"+to_chinese(skill)+"��"+SKILL_D(skill+"/"+pfm)->name()+"��������÷�����������ûѧ���������书����Ҫ�����Ŵ�ѧ����\n");
				write("�������书������ʹ����(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;				
			}
			write("��ѡ����ת��ʱ�����书��"+to_chinese(skill)+"���Լ���Ӧ�ľ��У�"+SKILL_D(skill+"/"+pfm)->name()+"��\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me,skill,pfm);
			break;
		case 1:
			if (!arg)
				return notify_fail("ת����ʽΪ��suicide -r �书 ֪ʶ����\n");
			if (sscanf(arg,"%s %s",skill,lskill)!=2)
				return notify_fail("ת����ʽΪ��suicide -r �书 ֪ʶ����\n");
			//����书
			if (!me->query_skill(skill))
				return notify_fail("�㲢�������"+skill+"�书��\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("ѡ����书������֪ʶ���ܡ�\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("�㲻�ܲ��ܱ����ڹ���\n");
			//���֪ʶ����
			if (!me->query_skill(lskill))
				return notify_fail("�㲢����"+lskill+"����ܡ�\n");
			if ((SKILL_D(lskill)->type())!="knowledge")
				return notify_fail(lskill+"������һ��֪ʶ���ܡ�\n");
			dir = get_dir("kungfu/skill/"+skill+"/");
			cant = ({});
			for (i=0;i<sizeof(dir);i++)
			{
				pfm = dir[i];
				if (dir[i][<2..<1]==".c") 
					pfm = dir[i][0..<3];
				if ( !me->query("perform/"+pfm)
				&& !SCBORN_D->valid_perform(me,skill,pfm) )
					cant += ({ ("kungfu/skill/"+skill+"/"+pfm)->name() });
			}
			if (arrayp(cant))
			{
				str = "���޷�����"+to_chinese(skill)+"��"+implode(cant,"��")+"�����÷���\n";
				str += "�㲻��ʹ����Щ���ܣ�����û�д����Ŵ�ѧ�á�\n";
				write(str+"�������ⲿ�ֵ�����ʹ����(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;								
			}
			write("��ѡ���˶���ת��ʱ�����书��"+to_chinese(skill)+"���Լ�֪ʶ���ܣ�"+to_chinese(lskill)+"��\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me,skill,lskill);
			break;
		case 2:
			if (!arg)
				return notify_fail("ת����ʽΪ��suicide -r �书 �ڹ�\n");
			if (sscanf(arg,"%s %s",skill,fskill)!=2)
				return notify_fail("ת����ʽΪ��suicide -r �书 �ڹ�\n");
			//����书
			if (!me->query_skill(skill))
				return notify_fail("�㲢����"+skill+"����书��\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("֪ʶ���ܻ�ȫ�����棬����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("��ֻ�ܱ���һ���ڹ���\n");
			//����ڹ�
			if (!me->query_skill(fskill))
				return notify_fail("�㲢����"+fskill+"����ܡ�\n");
			if (!(SKILL_D(fskill)->valid_enable("force")))
				return notify_fail(fskill+"������һ�������ڹ���\n");
			write("��ѡ��������ת��ʱ�����书��"+to_chinese(skill)+"���Լ��ڹ����ܣ�"+to_chinese(fskill)+"��\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me,skill,fskill);
			break;
		case 3:
			if (!arg)
				return notify_fail("ת����ʽΪ��suicide -r �书 �书\n");
			if (sscanf(arg,"%s %s",skill,skill2)!=2)
				return notify_fail("ת����ʽΪ��suicide -r �书 �书\n");
			//����书1
			if (!me->query_skill(skill))
				return notify_fail("�㲢����"+skill+"����ܡ�\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("��ת�ᱣ��֪ʶ���ܣ�����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("��ת�ᱣ�������ڹ�������Ҫ�ر�ָ����\n");
			//����书2
			if (!me->query_skill(skill2))
				return notify_fail("�㲢����"+skill2+"����ܡ�\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("��ת�ᱣ��֪ʶ���ܣ�����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("��ת�ᱣ�������ڹ�������Ҫ�ر�ָ����\n");
			write("��ѡ�����Ĵ�ת��ʱ�����书��"+to_chinese(skill)+"���Լ��书��"+to_chinese(skill2)+"��\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me,skill,skill2);
			break;
		case 4:
			if (!arg)
				return notify_fail("ת����ʽΪ��suicide -r �书 �书\n");
			if (sscanf(arg,"%s.%s %s",skill,skill2,skill3)!=3)
				return notify_fail("ת����ʽΪ��suicide -r �书 �书\n");
			//����书1
			if (!me->query_skill(skill))
				return notify_fail("�㲢����"+skill+"����ܡ�\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("��ת�ᱣ��֪ʶ���ܣ�����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("��ת�ᱣ�������ڹ�������Ҫ�ر�ָ����\n");
			//����书2
			if (!me->query_skill(skill2))
				return notify_fail("�㲢����"+skill2+"����ܡ�\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("��ת�ᱣ��֪ʶ���ܣ�����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("��ת�ᱣ�������ڹ�������Ҫ�ر�ָ����\n");
			//����书3
			if (!me->query_skill(skill3))
				return notify_fail("�㲢����"+skill3+"����ܡ�\n");
			if ((SKILL_D(skill3)->type())=="knowledge")
				return notify_fail("��ת�ᱣ��֪ʶ���ܣ�����Ҫ�ر�ָ����\n");
			if (SKILL_D(skill3)->valid_enable("force"))
				return notify_fail("��ת�ᱣ�������ڹ�������Ҫ�ر�ָ����\n");
			write("��ѡ�������ת��ʱ�����书��"+to_chinese(skill)+"���书��"+to_chinese(skill2)+" �Լ��书��"+to_chinese(skill3)+" ��\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me,skill,skill2,skill3);
			break;
		case 5:
			write("�������˵�����ת����\n");
			write("����������������ȷ�ϣ�");
			input_to("check_scborn",me);
			break;
		default:
			return notify_fail("��û���ṩ��ת����ת����\n");
	}
	return 1;
}

int sure1(string arg,object me,string skill,string pfm)
{
	if (!arg)
	{
				write("�������书������ʹ����(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("��ѡ����ת��ʱ�����书��"+to_chinese(skill)+"�Ҳ������κξ��С�\n");
			write("����������������ȷ�ϣ�");
		input_to("check_scborn",me,skill,0);
	}
	return 1;
}
int sure2(string arg,object me,string skill,string lskill)
{
	if (!arg)
	{
				write("��������������ʹ����(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("��ѡ����ת��ʱ�����书��"+to_chinese(skill)+"�Ҳ��������־��С�\n");
			write("����������������ȷ�ϣ�");
		input_to("check_scborn",me,skill,lskill);
	}
	return 1;
}
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2)
{
	object link_ob;
	string old_pass;
	string id;
	string file;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	id = getuid(me);
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}
	SCBORN_D->reborn(me,skill,etc1,etc2);
//	write("�����quit�ˡ�\n");
	me->move(VOID_OB,1);
	me->save();
	seteuid(getuid());
	file = sprintf(DATA_DIR "suicide/scborn/%s"+ SAVE_EXTENSION,  id);
	assure_file(file);
	cp(me->query_save_file() + SAVE_EXTENSION ,file);
	"/cmds/usr/exit"->savequit(me);
}
int help (object me)
{
	write(@HELP
ָ���ʽ: suicide [-f|-r]
 
    �����Ϊĳ��ԭ���㲻����ˣ������ѡ����ɱ����Զ��ȥ���ϡ�ϵͳ��
Ҫ��������������ȷ����ݡ�

suicide -r : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ������ϣ�ϵͳ��Ҫ��������������ȷ����ݡ�
 
������ѡ�� :)
 
HELP);
	return 1;
}
